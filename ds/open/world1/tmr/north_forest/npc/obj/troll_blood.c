inherit ITEM;

void create()
{
    set_name("���]��G", ({"troll blood", "blood"}));
    if( !clonep() ) {
        set("long", "�@�~���]���t�����G�A�w�e�b���T���A�C");
        set("unit", "��");
        set("value", 100);
        set("unit", "�~");
        set("weight", 20);
        } else
	set_default_object(__FILE__);
    setup();
}

