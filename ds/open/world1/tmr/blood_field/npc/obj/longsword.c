#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( "�簩���C" , ({ "barebone sword","sword" }) ); 
	set("long", "�o�O�@��C���n�n��᪺���C�A�C�b����W�U�C\n");
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
  	{
		set("unit", "��");
		set("material", "bone");
		set("value",3500);
	}
	set("weapon_prop/str",1);
	init_sword(40); 
	setup();
}



