#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", NOR""+
"�o�O�G�Ӫ������ո̭���|���A���O�گפ��������D�A���O�M�H\n"+
"�����A�O�H���M��n�C���~�ݥX�h�O�����c�c���H�s�A�u�c�s�檺�n\n"+
"���@�M�G���C���L�h�Q�̪������ګ��٬O�ϱo�ȤH�ܱo�Q�������M�`�C\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"r07",
        "south" : __DIR__"r05",
]));
        set("objects",([
        __DIR__"obj/desk02" : 1,
        __DIR__"npc/10" : 1,
        __DIR__"npc/11" : 1,
]));
	setup();
}