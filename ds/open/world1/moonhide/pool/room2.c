#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�e�����J�g�[�A���O�N�����U�ԡA������R���g�[�P���h����
�A�ϱo�o�̪��g�[��F���M���A�A�ҥH�o�̨�B���O��d�H�ۡA�Q
�n�����������C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room5",  
  "south" : __DIR__"room3",]));
        set("no_clean_up", 0);

        setup();
}

