inherit ITEM;
void create()
{
        set_name("���Q", ({ "head black", "black" }));
        set("long",@LONG
�o�O�@���ٺ�`��������, ���̤j���S�x, �N�O���}����M
�s�K��, ���O�x�ª�, �]�����į��Q���n�{, ���į�q�`���O
�Q���Ӱ��Ĥު�, �S����k�ͭ�.
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 25);
		set("attr",([
			"hp":5,
			"mp":0,
			"ap":15,
			"wound":1,
			"yang":0,
			"yin":1,
			"fol":1,
			"animal":0,
			"plant":0,
			"needfire":28,
			"mixedtime":0,
			"poundtime":0,
			"can_eat":0,
		]));
        }
        setup();
}
