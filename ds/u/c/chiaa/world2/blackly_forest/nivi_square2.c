//u/c/chiaa/world2/blackly_forest/nivi_square2.c
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
        set("exits", ([ /* sizeof() == 1 */
  "north"  : __DIR__"nivi_square1",          //�s��1
  
 ]));
       
        setup();
replace_program(ROOM);
}

