#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���i��");
        set("long", NOR""+
"�o�̬O���i�աA�ݰ_�ӫo�Q��������A�u���a�����a�観�X�i��\n"+
"�l�A�Ȥl��Q�����¡A�Q���F�ǹСC���O�a�W���@�B���㰮�b���a��\n"+
"�A���G���H�g�`�b�����ʡC\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"r14",
        "down" : __DIR__"r12",
]));

	setup();
}