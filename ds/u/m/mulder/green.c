#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","��q");
        set("long",@LONG
�o�̬O �Ң᪺�u���q�v�ްV�ҡA�p�G�A�Q�e��o�̡A��ܧA�H��
�F�C���W�h�A �Цn�n���Ϭ٤@�U�A���ҧ@�Ҭ��A�Q���}���ܥu�n�T�w
�A���A�ǥ���W���A�N�i�H�i�D�Ův�A�ХL��A�e�X�C
LONG
        );
        set("hide_exits",([
  "out" : "/d/wiz/hall1.c",
]));
        setup();
}

void init()
{
        if ( !wizardp(this_player()))
        {
                add_action("break_cmd","",1);
                call_out("green", 2, this_player());
        }
        else 
        {
                add_action("do_summon","sum");
        }
}

int break_cmd()
{
        if((string)query_verb() == "look") return 0;    
        if((string)query_verb() == "say") return 0;    
        if((string)query_verb() == "help") return 0;
      if((string)query_verb() == "recall") return 0;
        tell_object(this_player(),"�A�b�ްV�� �A�u��Ulook,help �G�ӫ��O �C\n");
        return 1;
}

void green()
{
        tell_room(environment(this_player()),
                "�Ať�����ǨӺ�q�p�]�����q�n: \n\n"+
        GRN     "�o��q���@����  �b��]�̷n�ڷn\n"+
                "�h�Q�r�p�]�b�ڪ��߮����ư���\n"+
                "���ڪ��q�n�H���L��  �j�}�F�p����î\n"+
                "���ڪ��J���H���y��  ���_�a�V�p�ɶD\n"+
                "���l�𪺪��v������ڪ����N\n"+
                "���A�������ӫG�F�ڪ���\n"+
                "�o��q���]�w�g�o�˨I�R\n"+
                "�h�Q���p�������٬O�q�q�L�y\n\n"NOR
        );
        return;
}

int do_summon(string str)
{
        object me=this_player(),ob;
        if ( !str ) return notify_fail("<Syntax>: Summon <player id>\n");
        if( this_player()->query("id")!="mulder")return 0;        
        ob = LOGIN_D->find_body(str);
//      tell_room(environment(ob),"�ѪŤ����X�@���j��Χ٥O�������T���k"+(string)ob->query("name")+"��F�_��, �M�ᤣ���F.\n", ob);
//      tell_object(ob,"�@�����A��F�_��, �A���e�@�}��....\n");
        ob->move(environment(me));
        ob->set("startroom", "/u/c/cominging/green.c");
        tell_object(me, "�A��"+(string)ob->query("name")+"���A�����e.\n");
//      tell_object(ob,".... ���Ӯɵo�{�O"+(string)me->query("name")+"��A�˹L�Ӫ�.\n");
//      tell_room(environment(ob),(string)ob->query("name")+"��M�X�{"+"�b�A���e\n",({me,ob}));
        return 1;
}

