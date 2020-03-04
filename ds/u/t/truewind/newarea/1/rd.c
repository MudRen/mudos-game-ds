#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�K���ӫe�|");
        set("long", NOR""+
"�o��O�K���ӫe�|�A�u�����a����ä�A�n�����R�C�o�઺���\n"+
"��جO���]�����S�a���ӥX�Ӫ��A�O�G�`�~�}��A�O�o�@�a�ϧO�o��\n"+
"�������@�C�ڻ������ä��������ͯf���H���S�O���v���ĪG�C\n"+
"    "HIM"����"NOR"(Sakura tree)\n\n");

        set("current_light", 0);
        set("outdoors","land");
        set("item_desc",([
        "tree":"�@�Ƭ��R������A�ݤF�u�O�H���m���ɡC\n",
        ]));
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"ra",
        "north" : __DIR__"rc",
        "west" : __DIR__"r01",
]));
	setup();
}
       void init()
{
        add_action("do_move","move");
}
int do_move(string arg)
{
        object me=this_player(),flower;
        flower = new(__DIR__"obj/flower.c");
        if( arg !="tree" && arg !="����" )
                return notify_fail("�A�n������F��H\n");
        else if( !me->query_temp("rflower")) {
                message_vision("����Q�o��ΤO�@���N���F��ä�U�ӡA�A���Ⱶ��C\n",me);
                me->set_temp("rflower",1);
                flower->move(me);
        } else {
                message_vision("$N�ΤO�@���S���۾�A�ϦӶ^�F�Ӫ��Y�ˡC\n",me);
                me->receive_damage("hp",10);
        }
        return 1;
}