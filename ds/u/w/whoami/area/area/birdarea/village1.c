#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG 
�A�ש󨫥X�F�h�A�a�a, �A���T�ߤ���U�@���j��, �A���U
�F�|�P, ��L���G�S�����e���˭Z�K�F, �A���F�観�@���d�g��
, �n�����H�̦b�����ʪ��ˤl.
LONG
    );
 
 set("exits",(["north":__DIR__"en32",
               "east":__DIR__"village2",
           ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

