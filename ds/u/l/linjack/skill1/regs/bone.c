inherit ITEM;
void create()
{
        set_name("�갩", ({ "tiger bone", "bone" }));
        set("long",@LONG
�o�ӪF�����M�s�갩, �������ӷ��o���@�w�O�Ѫ�, �u�n�O�ͩ�
�r�ɪ��j���׭��ʪ�, ���q�e�i�H���o�o���ħ�. �갩���ǬO���I��
��, ���Ǥ]�����Y��, ��L���������N����֨�. �o���ħ���O�ʪ�
�ʪ�, �ӥB�ĩʻ�P. �갩�j�������n�g�L�B�z�~�|���@�w���Į�.
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 40);
		set("attr",([
			"hp":20,
			"mp":-10,
			"ap":30,
			"wound":0,
			"yang":1,
			"yin":0,
			"fol":0,
			"animal":1,
			"plant":0,
			"needfire":55,
			"needfol":1,
			"mixedtime":0,
			"poundtime":-1,
			"can_eat":0,
		]));
        }
        setup();
}
