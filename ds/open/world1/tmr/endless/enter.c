#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIY"�L����"NOR);
        set("long",  
HIY"\n"
HIY"  �z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n"
HIY"  �x�����������������������������������������������������������������x\n"
HIY"  �x�����������������������������������������������������������������x\n"
HIY"  �x                                                                �x\n"
HIY"  ��================================================================�� \n"
HIY"    �x�����@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                           �����x \n"
HIY"    �x����                                                         �����x \n"
HIY"    �x����                                                         �����x \n"
HIY"    ��=============================================================�� \n"
HIY"      �x                        �i�L����j �@�@�@�@�@�@�@�@�@     �x  \n" 
HIY"      ������������������                          ������������������  \n"
HIY"        ========================����������========================    \n"
HIY"       �x                       �x  �x  �x                       �x   \n"
HIY"       �x                       �x o�xo �x                       �x   \n"
HIY"       �x=======================�x__�x__�x=======================�x   \n"
        );
        set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"room1",
   "north" : "/open/world1/tmr/frost/temple.c",
]));


        set("light",1);
        setup();
}

