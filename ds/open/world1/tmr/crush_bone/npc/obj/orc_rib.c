inherit ITEM;

void create()
{
    set_name("�b�~�H�ذ�", ({"orc's rib", "rib", "_CRUSH_BONE_RIB_"}));
    if( !clonep() ) {
        set("long", "�@���O�O���ذ��A���~�H��.. ~.~!");
        set("value", 10);
        set("unit", "��");
        set("weight", 20);
        } else
		   set_default_object(__FILE__);
    setup();
}
