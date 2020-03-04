inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�W�[", ({ "smell bad garlic", "garlic" }));
        set("long",@LONG
�o�O�@�دS�O���[�Y, ���D��@��Ʋz�Ψ쪺�[�Y�n�ӱo�W,
���O�@���ħ�, �H�s�@�v�֥~�˪��Ĭ��D, ���i�H�ͦY, ���L��
�_�Ӫ����D���h��N���o�Ӫ��o�C
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 20);
                set("heal",([
			"hp":5,
			"mp":-25,
			"ap":20,
		]));
		set("attr",([
			"hp":0,
			"mp":0,
			"ap":0,
			"wound":4,
			"yang":0,
			"yin":1,
			"fol":0,
			"animal":0,
			"plant":1,
			"needfire":40,
			"mixedtime":0,
			"poundtime":-1,
			"can_eat":1,
		]));
                set("food_remaining", 1);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) || !this_object()->query("attr/can_eat") ) return 0;
        me=this_player();
        if(me->query("mp")<24)
        {
                return notify_fail("�A���믫�O(MP)�w�g�����F, �A�Y�N�}���o�C\n");
        }
        else
        {
                set("heal",([
			"hp":5,
			"mp":-25,
			"ap":20,
		]));
                return ::do_eat(arg);
        }
}
