#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����A",({"waterman cloth","cloth"}) );

        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
         set("long","�o�O����̱`�諸�@�ئ�A�A�������ƤW�d�U�F\n"
                    "�I�I�Q�{�A�b�e���i�l���a��]�[�F�ɤB�C\n"
          );
         set("material", "cloth");
         set("unit", "��");
         set("value",150);

         set("armor_prop/armor", 3);

        }
        setup();
}

