// Room: /open/world3/tmr/basic/hotel_2f.c
//update -By Tmr- 2000/4/9

inherit ROOM;

void create()
{
        set("short", "�s�]�G��");
        set("long", @LONG
�A���b�s�]���G�ӡA�A�i�H�M���۬ݨ�̨ä��O���j�ٳܰs�Y���ΡA
���Q�ƥx�L���Ǫi�������[�]�b���A�A�i�H�z�L�o�Ǿ����s�W�@�ɺ����A
�ɨ��\�h�A�ȡC
LONG
        );
        set("world", "future");
        set("light", "1");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
          "down" : __DIR__"hotel",
        ]));
        set("item_desc",([
"�L���Ǫi��":"�ݩ����Ū��W�������A�A�i�H���W�Y��help��A�H���o������T�C(push help)\n",
        ]) );

        setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
	me=this_player();
        if(!arg || arg!="help")
                return notify_fail("���G�S���o�ӫ���C\n");
        tell_object(me,@long

���L���Ǫi���A�Ȩt�Ρ�

            �u�W�A�ȡG     ���O�G

�q�l�b����b(virement)    100 Dsg

long
);

return 1;
}

