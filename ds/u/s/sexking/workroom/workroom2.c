#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"��g�Z��"NOR);
        set("long", @LONG
�o�̬O�@���ܯ䪺�Z��..�A�o���ְk�]�~�棬..
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"workroom3",
        ]));
        set("item_desc",([
        "��g����":"�@�ӫܯ䪺����,���G�ܤ[�S�R���ˤl��C\n",
        "��g������s":"�ѩ�o�̹�b�ӯ�F��A�Ԥ���Q��(push)�U�R��(���s)�C\n",
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
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
        if (!arg || arg!="���s") return 0;
        message_vision(HIY"$N���Y��M�Q�l�차���,�n�ޣ��I�C\n"NOR,me);
        me->move("/d/wiz/hall1");
        return 1;
}



