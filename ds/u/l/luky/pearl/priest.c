// Room: /d/cham/mguild.c

#include <ansi.h>
#include <path.h>
#include <room.h>
inherit ROOM;
inherit F_GUILD;
void greeting();
void create()
{

set("short","[1;34m�i[32m���v�u�|[34m�j [0m");
set("long", @LONG

    �o�̬O���v�u�|�C²�檺�\�]��ܥX��¾�H���@�e�����믫, �@���i�o
��, �A�ߨ�`�N��j�U�������@�y���j���C�q����J��, ��ǩ�F�\�h���y��
�ѤH�b��ë�i�b���C�o�̪��O�����ǩ��t, �ܮe�������H���߱����R�U�ӡC

LONG
);
set("exits", ([ /* sizeof() == 1 */
"east":__DIR__"pearl_37",
]));
set("objects",([
LUKY+"pearl/npc/clemaster":1,
]));
set("light",1);


      set("valid_startroom", 1);
    set("no_clean_up", 1);

	setup();
replace_program(ROOM);
}
/*
void init()
{
greeting();
}
*/

/*
void greeting()
{
if(this_player()->query("birthday"))
if(this_player()->query("level")>35)
{
write(HIY"���f���u�þצ�A,�����A�i��\n"NOR);
this_player()->move("open/clc/room1/road6");
}
if(this_player()->query("pet"))
this_player()->move("open/clc/room1/road6");
}
*/
