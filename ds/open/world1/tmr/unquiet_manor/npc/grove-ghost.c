#include <ansi.h>
#include <skill.h>

inherit NPC;

void create()
{
    set_name("�L���Ѱ�", ({ "grove ghost", "ghost", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
�o�O�@�Ӧ��F���X�ʦ~������A��������Q�I�b�i��U�A
�l���F�i�𪺺���Ӧ��ΡC
LONG);

	set("title",HIG"�L�����"NOR);
    set("age", 60);
	set("level", 40);
    set("race","celestial");
    set("attitude", "aggressive");
    setup();
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 50 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 50 )	carry_object(__DIR__"obj/blood_meat");

}
