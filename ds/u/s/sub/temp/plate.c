
inherit ITEM;

void create()
{
	set_name("���P",({"sky plate","plate"}) );
	set("long","�@���ª����y�����P�A�W�Y�ζº��D�D�G�u�ൽ�@�c-�ƹL�v�C\n");
      set_weight(500);
	if(clonep() )
		set_default_object(__FILE__);
  else
   {
          set("value",0);
         set("unit","��");   //luky
	}
	setup();
}
