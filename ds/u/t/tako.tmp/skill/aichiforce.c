inherit SKILL;


int valid_enable(string usage)
{
        return (usage=="force");
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("�A����Τ��O�����M����m�ӷ��ߪk�C\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�A�L�L�ӧ��ӵۤߪk�B�_�ӷ��ߪk�C\n");

        return 1;
x
}
string exert_function_file(string func)
{
    return CLASS_D("taichi") + "/taichiforce/" + func;
}

