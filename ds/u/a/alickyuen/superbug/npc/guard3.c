inherit NPC;

void create()
{
	set_name("ĵ��", ({ "policeman" }) );
	set("long", "�@��ĵ��A���b�l�����{���C\n");
	set("race","�H��");
set("age",50);
	set("level", 40);
                set_skill("gun", 70);
                set_skill("combat", 75);
set_skill("dodge",50);
set_skill("parry",50);
    set("chat_chance",10);
        set("chat_msg",({
//     (: random_move :),
 //               (:command("wield gun"):),
                         (:command,"reload clip":),}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):),
         }) );
                set("talk_reply","�A�����ڤ@�I�p��(help)�ܡH\n");
                set("inquiry/help","�ڦb�l�����{���A�A�@�N���ڶܡH\n");
	setup();
 carry_object(__DIR__"wp/clip2.c");
carry_object(__DIR__"wp/gun2.c")->wield();
carry_object(__DIR__"eq/suit.c")->wear();
}
void init()
{       

        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_arrest","arrest");
add_action("do_nod","nod");
}

int do_arrest(string arg)
{
        object me,obj, obj2;
obj2=this_object();
        me=this_player();
if(!me->query_temp("find_killer")) return 0;
{
        if( !arg ) return notify_fail("�A�Q�e���֡H\n");
   if(me->is_busy() ) return notify_fail("�A�����ۡC\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("�o�̨S���o�تF��C\n");
        if( !obj->is_character() || obj->is_corpse() ) return 0;
if (arg!="killer") return notify_fail("�o�Ӥ��Oĵ��Q�e�����H�C\n");
if (arg="killer") 
        {
command("snort killer");
command("say �ڭ̥����L�쭫�˧a�C");
//message_vision("$N���$n�ܹD�R�u�ѩǪ��T���餣�O�A���N�O�ڬ��T�v",me);
me->kill_ob(obj);
obj2->kill_ob(obj);
        }
}
               return 1;
}

int do_nod(string arg)
{
      object me;
      me=this_player();
if(me->query_temp("find_killer")) return 0;
{
       command("say ���ڭ̴N�X�o�h��a(arrest)�C\n");
command("follow "+me->query("id"));
       me->set_temp("find_killer",1);
}
}
void greeting()
{
object me;
me=this_player();
          if(!me->query_temp("killed_killer") && !me->query_temp("find_killer")  || !query_temp("killed_killer") && !me->query_temp("find_killer") ) return 0;
 {
command("say �h�§A�����U�C");
command("thank "+me->query("id"));
command("say �o�̦��@�ǳ��S�O���A���C");
message_vision("ĵ��ǰe�F���������ӳ�쪺�q�l���h$N����f���C\n",me);
command("follow none");
me->delete_temp("killed_killer");
me->delete_temp("find_killer");
me->receive_money(1000);
}
}
