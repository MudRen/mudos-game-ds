
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����",({"beefsteak"}) );
	set_weight(10);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�o�Ӥ��ƪ����׭�n�X�A���f��,�i�n���֦Y��,�K�o���|�D���N���n�Y�o�C\n");
	set("unit", "��");
	set("value",700);
	set("food_remaining",2);
	}
}
