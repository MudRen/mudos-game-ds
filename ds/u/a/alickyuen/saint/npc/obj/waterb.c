//updated 26/12
inherit ITEM;
void create()
{
set_name("���s", ({ "water bottle","bottle" }) );
set_weight(80);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "�@��ܦh�~�e�X�������s�C\n");
set("unit", "��");
set("value", 0); 

}
}
