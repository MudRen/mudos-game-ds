#include <ansi.h>
inherit ITEM;

string *msg = ({
"  ",
HIW"\n  $N�N���]���F�X�ӡC\n"NOR,
HIW"\n  ���]�W�g�ۡu���ߵo�]�v���S���r�ˡA���L�~����^�C\n"NOR,
HIW"\n  $N���Ī��N���]���}.....�C\n"NOR,
HIC"\n�z...���]�̭��O.... "NOR,
});

void create()
{
  set_name(HIR"���]"NOR,({"red envelope","bag","envelope"}));
  set("long","�o�O�@�ӹL�~���i�ɡA�j�H�ΨӰe���p�Ī��F��A�̭��q�`����ߡC\n"
             HIW"�n���}���]��"HIC"open"NOR"�C\n");
  set("weight",1000);
  if( clonep() )
  set_default_object(__FILE__);
  else
  {
    set("value",100);
    set("unit", "��");
    set("needaward",1);
  }
  setup();
}

void init()
{
  add_action("do_open","open");
}

void do_loop(object me,object ob,object gift,int index,string obname)
{
  string cmsg;
  if(sizeof(msg) != index)
  {
    index++;
    if(index > 4)
    {
      call_out("do_loop2",1,me,ob,gift,obname);
      return;
    }
    cmsg = msg[index];
    message_vision(cmsg,me);
    call_out("do_loop",1,me,ob,gift,index,obname);
  }
}

void do_loop2(object me,object ob,object gift,string obname)
{
  message_vision(obname + NOR"�I�I�I\n",me);
  gift->move(me);
  destruct(ob);
}

int do_open(string arg)
{
  string obname;
  object me,ob,gift,bag;
  int index = 0,index2 = 8,money,exp,award,temp=random(2); // index2 : §���@�X��
  ob = this_object();
  me = this_player();

  if(!arg || (arg != "bag" && arg != "envelope") ) return 0;
  if( environment()->query("redbag") > 3 ) {
     tell_object(this_player(),"������h�]...�o�@�I���O�H�}�a.\n");
     return 0;
  }
  this_player()->add("redbag",1);
  index2 = random(index2)+1;
  money = random(10000);
  exp = random(5000);
  bag = new(__DIR__"gift/none");
  switch(index2)
  {
    case 1 : obname = HIW+chinese_number((exp*2)+10000+temp)+"�I�g���";
             gift = new(__DIR__"gift/none");
             me->add("exp",(exp*2)+10000+temp);
             break;
    case 2 : obname = HIY"�@�U"+chinese_number(money)+"��";
             gift = new(__DIR__"gift/none"); // <-- �Ŭ��]�U
	     me->receive_money(10000+money);
             break;
    case 3 : obname = HIW+chinese_number(exp+5000)+"�I�g���";
             gift = new(__DIR__"gift/none");
             me->add("exp",5000+exp);
             break;
    case 4 : obname = HIW"�S��^�m�Ȥ@�I";
             gift = new(__DIR__"gift/none");
             me->add("award/totalvalue",1);
	     me->add("redbag",-1);
             break;
    case 5 : obname = YEL"�W�Ťj�ץ]";
             gift = new(__DIR__"gift/specialfood");
	     bag->move(me);
             break;
    case 6 : obname = HIR"�խ߼C�@��";
             gift = new("/open/world1/acme/area2/npc/wp/darksword");
	     bag->move(me);           
             break;
    case 7 : obname = HIM"�I�G���";
	     gift = new("/open/world1/tmr/area/npc/obj/dragon-blood");
	     bag->move(me);
             break;
    case 8 : obname = HIC"���O���q��";
             gift = new("/open/world2/shengsan/aovandis/npc/obj/notebook");
             bag->move(me);
             break;
  }
  call_out("do_loop",1,me,ob,gift,index,obname);
  return 1;
}
