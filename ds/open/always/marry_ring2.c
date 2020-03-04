#include <ansi.h>
#include <armor.h>
inherit FINGER;

string getage(object ob);
void query_each_other(object me);

void create()
{
  set_name(WHT"���B�٫�"NOR,({"marry ring","marry","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("basic_long",HIW"���O - ���˷R���H��������: honey <��r>\n"NOR+WHT"�o�O�@�u�»Ȼs�������A�W�����^�F�@���p�p���p�ۡC\n�W�Y��F�@��p�p���r�G�ڪ��ܷR "NOR);
    set("value",0);
    set("material","diamond");
    set("no_drop",1);
    set("no_sell",1);
    set("no_sac",1);
    set("unit","�u");
  }
  setup();
}

void init()
{
  object me = this_player();

  add_action("do_honey","honey");
  add_action("do_honey_nick","honey_nick");

/*  if(!me->query("marry_id"))
  {
    call_out("error_msg",2);
    return;
  }*/
  set("wear_msg",NOR+WHT"$N���W$n"WHT"�A��Ѥj�ۡy�˷R�� "HIC +me->query("marry_id")+ NOR+WHT" �н�P�ڷR���O�q�I�z�C\n"NOR);
  set("unequip_msg","$N��U�@�u$n�C\n");

  remove_call_out("query_each_other");
  call_out("query_each_other", 0, me);
}

void query_each_other(object me)
{
        object ob;
        string str;

        if( !me ) return;
        if( !str=me->query("marry_id") )
        {
                call_out("error_msg", 2);
                return;
        }
        ob = new("/obj/unnamed.c");
        if( !ob->query_restore(str) )
        {
//              write("**DEBUG** ob uid:"+ getuid(ob) + " ob euid" + geteuid(ob) +"\n");
                write(HIR" (�A���t�@�b�w�g�����F.. �٫��N�۰ʾP���C )\n"NOR);
                message_vision(HIG"�u��$N�����Ʀa�A�N���B�٫������F...�C\n"NOR, me);
                me->delete("marry_id");
                destruct(this_object());
                destruct(ob);
                return;
        }
        else if( ob->query("marry_id") != getuid(me) )
        {
//              printf("**DEBUG** object: %s level: %d marry_id: %s ob_uid: %s ob_euid: %s\n", file_name(ob), ob->query("level"), ob->query("marry_id"), getuid(ob), geteuid(ob));
                write(HIR" (���G"+gender_self(me->query("gender"))+"���t�@��w�ܤF��..�C )\n"NOR);
                message_vision(HIY"$N�ˤߦa�N$n�����A���b�Ů𤤡A���������F��\n"NOR, me, this_object());
                destruct(this_object());
                destruct(ob);
                return;
        }
        else if( ob ) destruct(ob);
        return;
}

void error_msg()
{
  write(HIC"�A�����B�٫����G�X�F�@�ǰ��D�A���ݻ��֦^���Ův�C\n"NOR);
  return;
}

int do_honey(string str)
{
  object ob, me = this_player();
  if(!me->query("marry_id")) return notify_fail("�A�����B�٫��W�èS����ۧA�t�����W�r�I�л��֦^���Ův�I\n");
  if(!str) return notify_fail("�A�Q��A���t�@�b������?\n");
  ob = find_player(me->query("marry_id"));
  if(!ob || !environment(ob)) return notify_fail("�A���t���i���٨S�W�u�A�άO�v�g���u�F�A�]���L�k�ǰe�T���C\n");
  tell_object(ob,HIR +getage(ob)+ ", "NOR+WHT +str+ "\n"NOR);
  write(HIR"To " +getage(ob)+ ", "NOR+WHT +str+ "\n"NOR);
  return 1;
}

string getage(object ob)
{
  object me = this_player();

  /* --------- �Ȯɨ����̦~�ֺ٩I ------------
  if(ob->query("gender") == "�k��")
  {
    if(ob->query("age") < 30) return "�_��";
    if(ob->query("age") < 50) return "�ѱC";
    if(ob->query("age") < 70) return "�Ѧ�";
    return "�ڻ��ѤӱC��";
  }
  else
  {
    if(ob->query("age") < 30) return "�˷R��";
    if(ob->query("age") < 50) return "�Ѥ�";
    if(ob->query("age") < 70) return "�Ѧ�";
    return "�ڻ����Y�l��";
  }
    -------------------------------------------------------- */
  if(me->query("marry_nick")) return me->query("marry_nick");
  return "�˷R��";
}

int do_honey_nick(string str)
{
  if(!str) return notify_fail("�A�Q�٩I�A���t�@�b������?\n");
  if( strlen(str) > 16 ) return notify_fail("�W�r�����Ӫ��F�A�зQ�@�ӵu�@�I��.\n");
  this_player()->set("marry_nick",str);
  write("Ok.\n");
  return 1;
}

string long()
{
  if(this_player()->query("marry_id")) return query("basic_long") + HIC +this_player()->query("marry_id") +"\n"NOR;
  return query("basic_long") +HIY"�o�̳��M���򳣨S��?! ���ݻ��֦^���Ův�C\n"NOR;
}

int query_autoload() { return 1; }

