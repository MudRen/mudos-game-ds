#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"�g�s�������O"NOR, ({ "quest board", "board" }) );
        set("location", "/open/world1/cominging/area/dragon/fire_dragon");
        set("board_id", "dragon_quest_b");
        set("long",
        "�o�O�@�Ө������̸Ѱg�Ϊ��d���O�C\n");
        setup();
        set("capacity", 99);
        set("master",({"andygi"}));
}
