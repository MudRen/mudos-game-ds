#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("�P�x��",({"ruling pen-holder","pen","holder","pen-holder" }));

        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�O�@��j�򵧡A��M�`���򵧤j�ܦh�A�L�����򦳦p������W�Q�A�o�N�O�U�٪��u�P�x���v�C\n");
                set("unit", "��");
                set("value", 1400);
                set("material", "iron");
        }
        init_dagger(18,POINTED);
        setup();
}
