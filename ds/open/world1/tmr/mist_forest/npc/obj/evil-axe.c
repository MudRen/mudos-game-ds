#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("���]��", ({ "huge-evil axe","axe"}) );
        set_weight(10000);
          setup_axe(4, 6,120, 0);

        if( !clonep() ) {
                set("wield_as", ({"twohanded axe"}));
                set("unit", "��");
                set("value", 3500);
                set("rigidity", 80);
                set("long",@long
�@�@�o�O�@��y���_�S�����j���Y�A���Ӥj����W�W���ۤ@�ӭӪ��p�}�A
�b���R�ɷQ���|�a�_�}�}��ժ����n�C
long
                );
        }
        set("apply_weapon/twohanded axe", ([
                "str":2,
                "cps":-2,
        ]));
        setup();
}


