#include <ansi.h>
inherit NPC;
void gotoinn();

void create()
{
 set_name("���T",({"chen chi","chen","chi"}));
 set("long",@LONG
�ڻ��L���~���g���C�|���A����Ѧ~�~�^��]�a���p���פ�
���ɧu�u�֡A�@�@��A�������@�N���ͤ���I
LONG
    );
 set("attitude", "peaceful");
 set("age",64);
 set("nickname",CYN"�s������"NOR);
 set("evil",-10);
 set("gender","�k��");
 set("level",30);
set("str",100);
set("con",100);
 set_skill("sword", 100);
 set("chat_chance",10);
 set("no_kill",1);
 set("chat_msg", ({"���T�ĤF�@�f����G���D��u�藍�X��.....�H\n", 
        }) );
set("schedule",
([
    "00" : (: gotoinn :),
    "05" : (: gotoinn :),
    "10" : (: gotoinn :),
    "15" : (: gotoinn :),
    "20" : (: gotoinn :),
]));

 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

void gotoinn()
{
 int a=random(7);
        if(!find_object("/open/world1/tmr/area/hotel")) return;
        if(!find_object("/open/world1/cominging/area/hotel")) return;
        if(!find_object("/open/world1/acme/area/hotel")) return;
        if(!find_object("/open/world1/moonhide/area/hotel")) return;
        if(!find_object("/open/world1/wilfred/sand/room12")) return;
        if(!find_object("/open/world1/whoami/birdarea/village8")) return;
        if(!find_object("/open/world1/faceoff/sky/ten16")) return;

 message_vision("$N�����i�y�A�w�w�����F�X�h�E\n", this_object());
 if( a == 0 ) {
   if( file_name(environment(this_object())) == "/open/world1/moonhide/area/hotel" ) a++;
   else this_object()->move("/open/world1/moonhide/area/hotel"); 
 }
 if( a == 1 ) {
   if( file_name(environment(this_object())) == "/open/world1/cominging/area/hotel" ) a++;
   else this_object()->move("/open/world1/cominging/area/hotel");
 } 
 if( a == 2 ) {
   if( file_name(environment(this_object())) == "/open/world1/acme/area/hotel" ) a++;
   else this_object()->move("/open/world1/acme/area/hotel");
 }
 if( a == 3 ) {
   if( file_name(environment(this_object())) == "/open/world1/tmr/area/hotel" ) a++;
   else this_object()->move("/open/world1/tmr/area/hotel");
 }
 if( a == 4 ) {
   if( file_name(environment(this_object())) == "/open/world1/wilfred/sand/room12" ) a++;
   else this_object()->move("/open/world1/wilfred/sand/room12");
 }
 if( a == 5 ) {
   if( file_name(environment(this_object())) == "/open/world1/whoami/birdarea/village8" ) a++;
   else this_object()->move("/open/world1/whoami/birdarea/village8");
 }
 if( a == 6 ) {
   if( file_name(environment(this_object())) == "/open/world1/faceoff/sky/ten16" ) a=0;
   else this_object()->move("/open/world1/faceoff/sky/ten16");
 }
 message_vision("$N�����i�y�A�w�w�����F�i�ӡE\n", this_object());
}


int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 if(random(2))
 {
   if (me->query("int") > 30)
    {
        command("say �ݨӤp�ѧ����ӥi�H�����@�U�C");
        command("say �O�o�˪��G�e�X�ѥX�����ɦb�@���\\�]�ݨ�F�@�ӹ��p...");
      command("say �W�p�O�G�u��B�s���A�F�G�I�A��T�I�v�A���̦Ѥҫ��Q�]�Q���X�U�p ");
      command("say �p�ѧ̦p�G�諸��, �O�_�i�H����(answer)�@�U�H");
    }
    else
    {
        command("say �ѤҤ@�I�p�Ƥ����·Цѧ�....^^");
    }
 }
 return 1;
}

void init()
{
        add_action("do_answer","answer");
}

void clear() {
        if(!this_object()) return ;
        delete("quest");
}

int do_answer(string arg)
{
        object me,where1,p;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten42");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡: answer <�U�p>\n");
        if ( query("quest") ) {
            message_vision("���T�L���D: �h�¦ѧ̡A��~�w�g���H���йL�ѤҤF�I \n",me);
                return 1;
        }
        
        if( a == "���|���ȡA�W�C�M�A�U�K�M" || a =="���ʤ��ȡA�W�C�M�A�U�K�M" || a =="���ʤ����A�W�C�M�A�U�K�M" )
   {
      message_vision("$N�w�w�u�D�G"+a+"\n",me);
        message_vision("���T�h�F�@�h�A �H�Y����������$N����I \n",me);
        message_vision("���T���D: �p�ѧ̯u���̤]�I \n",me);
        message_vision("���T���D: ���Ǧ~�]�t�ڷ|�o��F�X�Ӥp�F��A�b�ڨ��W�]�S����ΡA�p�ѧ̮��h�a�I \n",me);
       message_vision(HIC"���T���F$N�@�Ǫ��⪺���ġI \n"NOR,me);
        new(__DIR__"obj/gold_pill.c")->move(this_player());
        set("quest", 1) ;
        call_out("clear", 1800 + random(1800));
        gotoinn();
        return 1;
    }

    message_vision("���T�n�F�n�Y�A���D:�����u���....\n",me);
    return 1;
}

