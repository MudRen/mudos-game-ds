#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�j��");

 set("long",@LONG 
�A�{�b�i�J�j��, �A�ݤF�ݥ|�P, �u�����k�U���@�ƪ��ѱ�
�۹�, �C�@�ӥ۹����O���P���ʧ@, �ӥB�ݮݦp��, �A���Ѫ��g
�İ_��, �_��M�n�䳣�O���H�{���ȩ�, �ӪF��q�����Y�C
LONG
    );
 
 set("exits",(["east":__DIR__"bird18",
               "west":__DIR__"bird14",
               "south":__DIR__"bird16",
               "north":__DIR__"bird17",
     ]));
 
 set("no_clean_up", 0);
 setup();
 set("light",1);
 replace_program(ROOM);
}           

