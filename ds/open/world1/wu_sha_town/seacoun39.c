#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short","�L��䤺");
        set("long",@LONG
�o�̤w�g�O�L��䤺�F, �A�i�H�o�{���_�����O�@�ǥ~��
�H, �i���_�䪺��D���O�q������������y�B, �ө��n�䪺��
�D�h�O�q�����߮����񪺰�a, �A�o�{�o�̪����������M��, 
�O�H�����U�h���İ�....
LONG
    );
        set("exits",([ "south":__DIR__"seacoun41",
  "west":__DIR__"seacoun37",
]));
        set("item_desc",([
  "����" : "�A�i�H�ݨ��������b�̭����, �p�G�Aı�o�a�ޤ���, ���ӥi�H��(jump in)�U�h�쳽...\n",
]));
        set("no_clean_up",0);
        set("outdoors","land");
        setup();
}            

void init()
{
        add_action("typejump","jump");
}

int typejump(string arg)
{
        object me;
        me = this_player();
        if( arg != "in ����" ) return 0;

        if( me->query_temp("ride") )
                write("�ݨӧA���y�M���G���Q��A�@�_���U�h��I\n");
        else if( me->query_skill("swim") > 10)
        {
                message_vision(CYN"$N �`�l�@�f��, �a���D�J����!!\n"NOR,me);
                me->move(__DIR__"map_4_5");
        }
        else message_vision(HIB"$N��������, �a���D�J����, �������W�~�l����, �_�h�@���p�R�j���]�S�F....\n"NOR,me);       
        return 1;
}

