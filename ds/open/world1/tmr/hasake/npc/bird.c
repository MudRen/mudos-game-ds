// �ѹa��
inherit NPC;
void create()
{
        set_name("�ѹa��", ({ "tian-lin bird", "bird" }) );
	set("race", "beast");
	set("age", 1);
	set("level",5);
        set("long", "�@�u���R���ѹa���A���઺�q�n���O�ѤW���ȹa�C
�o����u�b�ߤW�ۺq�A�դѺ�ı�C���H���A�o�O�ѤW���P�P���U�Ӥ����ܪ��C\n");
        set("attitude", "friendly");
	set("limbs", ({ "�L", "�ͻH", "���l" }) );
	set("verbs", ({ "bite", "claw" }) );
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);
	setup();
}
