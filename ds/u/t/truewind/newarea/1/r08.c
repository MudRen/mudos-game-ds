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
        "east" : __DIR__"r05",
        "north" : __DIR__"r07",
        "down" : __DIR__"r04",
]));
	setup();
}