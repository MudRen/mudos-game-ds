// test.c

inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object ob;
	if(!arg) return notify_fail("�n����ԣ?\n");
	ob = present(arg, environment(me));
	if(!ob) return notify_fail("�S���o�ӥͪ�..\n");
	if(userp(ob)) return notify_fail("���i�缾�a�ϥ�..\n");
	if(!ob->is_character()) return notify_fail("�S���o�ӥͪ�..\n");
//	SKILL_D("celestial")->hit_ob(me, ob, 50, 20);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    printf("wizard level: %d   status: %s\n", wiz_level(ob), wizhood(ob));
	return 1;
}

int help(object me)
{
write(@HELP
���O�榡 : test <�Y�H>

�ΨӴ��ժZ�\�ޯ઺�j�z�C
HELP
    );
    return 1;
}
