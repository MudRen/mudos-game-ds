inherit ITEM;
void create()
{
        set_name("����", ({ "shit" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long","�o�O�@�@�_��L�񪺪��ˡA�A���|�a�b���W�C\n");
           set("unit","�@");
           set("value",1);
        }
}
