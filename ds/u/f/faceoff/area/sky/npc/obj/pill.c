#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�E��^�", ({ "pill" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3000);
                set("long", "�@�ج۷���������ġA���L�ڻ����_�ġA�u�n�S�i�ç��A�����ĪG�I�I");
                }
        setup();
}

