#define WALLITEM "��������"
#define WALLLONG "�@�ӥѤ��D�������X�Ӧ����j�O���ɡC\n"
#define WALLID   "lightwall"

inherit ITEM;

void create()
{
	set_name(WALLITEM,({WALLID}));
	set_weight(99999);
	set("long",WALLLONG);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "�h");
		set("value",0);
		set("no_drop",1);
		set("no_get",1);
		set("no_sac",1);
		}
	setup();
}
