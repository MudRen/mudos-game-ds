#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Item Recover Shop");
        set("long", @LONG
�o�̴N�O Secret City�ߤ@���ө��F�A�ݨ��n�p�s���q���A�M�X�J
�o��ӦۦU�a���f�~�A�A���D�A�o�̤@�w���g�O�c�a�L�������A�u�O�b�V
����@�ݡA�ڰǡI�S�O�@�x���ǯŪ��W�ž����H....�����ٶK�۵���L��
���P�l�A�{�b�O�褸�X�~�F���I�٦b�γo�ؼлy�H
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec3.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/seller.c"   :1,
]));

        setup();
        replace_program(ROOM);

}


