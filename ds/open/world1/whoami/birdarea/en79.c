#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIW+BLK"�ۥ�"NOR);
set("long", @LONG 
�A�@�L���ƪ�����o�ӥۥ޸̡A�o�̼��o���H�H����F���s
���Y�C�b�ۥު��`�B�o�{�F�@�Ӻ��l�A�_�X�������V�C�����٦�
�@��W�u�ѤH���b���y�@��C�A�L��A����Ӧ��G�ܰ���, �b�o
�̤]���@�ӥ۹�, �i�O�n����A��~�Ҭݨ쪺���Ӥ@��.....
LONG
        );
        set("objects",([__DIR__"npc/ooldman" : 1,
                        __DIR__"npc/statue2" : 1,
               ]));
        set("no_clean_up", 0); 
        set("light",1);        setup();
}
void init()
{
        add_action("do_roll","roll");
}
int do_roll(string arg)
{
        object me;
        me=this_player();
        if (arg != "�۹����Y" && arg != "�Y") return 0;
        else {
               message_vision("�u��$N��"HIW+BLK"�۹�"NOR"���Y�@��A�X�{�F�@�ӳq���W�誺��l�C\n\n",me);
               set("exits",([
               "up" : __DIR__"en78",
               ]) );
           return 1;
        }
}          

