#include <ansi.h>
inherit NPC;
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
 set("chat_msg", ({"���T�ĤF�@�f����G���D��u�藍�X��.....�H\n", 
        }) );
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
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
int x=1;
int do_answer(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten42");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡: answer <�U�p>\n");
        if( a!="���|���ȡA�W�C�M�A�U�K�M" )
                return notify_fail("���T�n�F�n�Y�A���D: �����u���....\n");
    if (x != 0)
  {
      message_vision("$N�w�w�u�D�G���|���ȡA�W�C�M�A�U�K�M \n",me);
        message_vision("���T�h�F�@�h�A �H�Y����������$N����I \n",me);
        message_vision("���T���D: �p�ѧ̯u���̤]�I \n",me);
        message_vision("���T���D: ���Ǧ~�]�t�ڷ|�o��F�X�Ӥp�F��A�b�ڨ��W�]�S����ΡA�p�ѧ̮��h�a�I \n",me);
     x = 1;
   {
   else
   {
    message_vision("���T�L���D: �h�¦ѧ̡A��~�w�g���H���йL�ѤҤF�I \n",me);
   }
        return 1;
}

