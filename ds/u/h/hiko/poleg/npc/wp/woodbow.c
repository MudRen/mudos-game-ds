#include <weapon.h>
inherit BOW;

void create()
{
        set_name("��}",({"wood bow","bow"}));
        set("long","�o�O�@���s���j�}�A�i��(shoot)�g�X�b�C\n");
        set_weight(5000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value",850);
        set("volume",3);
        set("material","wood");
        }
        init_bow(13);
        setup();
}

