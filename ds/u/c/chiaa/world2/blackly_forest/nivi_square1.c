//u/c/chiaa/world2/blackly_forest/nivi_square1.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�s��");
        set("long", @LONG
�o�̬O�@�Ӥj�s��!���ɬO�Ԫ̧��H�̬��ʪ��a��,
�n�O���o�ͭ��j���Ʊ�,�άO���S���p,
�]�i�H��@�@�Ӷ��X���a�I!!

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south"  : __DIR__"nivi_square2",         //�s��2
  "north"  : __DIR__"nivi_road2",           //�ԧ��D��2
  "east"   : __DIR__"assembly_room",        //�|ĳ��
 ]));
       
        setup();
replace_program(ROOM);
}

