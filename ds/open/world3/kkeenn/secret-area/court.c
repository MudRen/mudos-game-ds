#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U�����ݪk�|");
        set("long", @LONG
�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{
    �x        ��                ��      �x
    �x������������������      ��        �x
    �x  ����      ����      ����        �x 
    �x  ��  ��  ��  ��    ����  ��      �x
    �x  ��    ��    ��  ��  ��    ��    �x
    �x  ��  ��  ��  ��      �������������x
    �x������������������    ��    ��    �x
    �x        ��            ��    ��    �x
    �x������������������    �������������x
    �x��      ��      ��    ��    ��    �x
    �x��      ��  ��  ��    ��    ��    �x
    �x��      ��  ��  ��    �������������x
    �x��      ������  ��    ��    ��    �x
    �x��      ��  ��  ��    ��    ��    �x
    �x��    ��      ����    �������������x 
    �|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
       "east":__DIR__"sec10.c",
]) ); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/judge.c" :1,
]));
        set("light",1);

        setup();
        replace_program(ROOM);

}

