#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("�S����������",({"wowdream death doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","��");
                set("long",
HIW"    ���@�@�@"HIB"    ��"NOR+HIW"�@�@�@  ���h��    \n"NOR+
YEL"��"HIY+BYEL"��"NOR+WHT"�i"NOR+YEL"�����@"BLU"��"CYN+BBLU"��"HIB+BBLK"�i"NOR+BLU"��"HIB"��"HIW"�@�����i��    "YEL"�j\n"NOR+
YEL"�i�i"HIW"�i"NOR+YEL"�i�i�@"BLU"�i�i"HIB"�i"NOR+BLU"�i"HIB"�i"HIW"�@�i�i�i�i�i"YEL"�j\n"NOR+
HIY"���i�i�����@"HIC"���i�i�����@"HIC+HBBLU"�i�g�i�g�i"NOR+HIY"   �j\n"NOR+
HIW"    ���@�@�@"HIB"    ���@�@�@"HIC+HBBLU"�i�g�i�g�i"NOR+HIY"   �C\n"NOR+
HIC+HBBLU"[2008/08/27 birthday]   �����������@�@�@\n"NOR
                );
                set("undead_msg",HIG"\n\t�N�b�d�v�@�v���ڡA$N���W��$n��M�ĥX�צ�F�o�P�R�@��!!\n\n"NOR);

        setup();
}


int query_autoload() { return 1; }

