#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
set_name( HIG"�Q"HIW"��"HIY"�F"HIW"��"NOR ,({"ten sword","sword"}));
        set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"
�@�ⴲ�o�X�F�����C,�W�����۵۵L�������_��,
�W�Q�L��,�s���Y���໴�P���}�C\n"NOR);
                set("volume",2);
                set("unit", "��");
                set("value",12500);
        set("limit_skill",60);
        set("material","silver");
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",35);
        }
        init_sword(80); 
        set("wield_msg","$N�q�y�کԥX�F�@��$n���b�⤤,��⪺���~��$N�������R��
                           �ۥ��~,���o�X���H���Ϊ��F�� �C\n");
        set("unequip_msg", "$N��U�⤤��$n, �N$n���J�y�ڪ��C�T��,�����������C\n");
        set("combat_msg", ({
   "$N�ϥX�Ĥ@���u��v,�C�y�o�X��⪺����,���R$n���� "  ,
   "$N�ϥX�ĤG���u�b�v,$N��Q���F�ʤW��U��,�C�b�٩�$n���y��",
   "$N�ϥX�a�T���u���v,�Q���F�ʭY���Y�{���X�{�b$n�����e,$N���n�B��,�@�خ��䪺����,��$n�P���ܦ���u�Ū��A,$n���ʧ@�C�F�b��,�A���է�C�W��,���V$n���L��",
   "$N�ϥX�ĥ|���u���v,�Q���F�ʥѤW�ۼA�ܤU,��$n���ⳡ�ӥh",
   "$N�ϥX�Ĥ����u�z�v,�Q���F�ʦ��p���Ī��z�}�n,��$n���I���h,���U�窺�C",
   "$N�ϥX�Ĥ����u�B�v,�Q���F�ʫ���ӤU,�t����H,�Q���F�ʺ������B,�ƦV$n",
   "$N�ϥX�ĤC���u�w�v,$N��Q���F�ʧֳt����,�q�Ů𹺹L�@��C��g��$n,���d�U�K�Ȱw",
   "$N�ϥX�ĤK���u�ʡv,�u���A�L�̰�ᦳ��,���M�@�y:�u�ʡv,$n�����驿�M����ʤF,\n
    �A��Q���F�ʩ�$n����@��,���n���i�F����,$n�~����ۨ��Z����V����",
   "$N�ϥX�ĤE���u�ߡv,$N��W����,���ͤQ�r,�Q���F�ʰj�ۤ@�g,�Y�X�ƹD�C��,\n
     �����g��$n����V,�u��$n�F����{", 
}) ); 
      setup();
}
void attack(object me,object victim)
{
        int damage,str,dex,random1;
        if( random(200)>150)
        {
        str = me->query("str")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIY"$N�ϥX�ĤQ���u�F�v,$N�[�𾮯�,�@�n�u�� ~ ~ ~�v���@�n\n�       ,�Q���F�ʩb�V�Ť�,$N�I�i�L�W���\,����Q���F�ʪ�����\n"NOR
        +HIC"�����Q���F�ʳQ�p�E��,���o�X�e�ҥ��������~ + + + + +\n"NOR          +HIR"�A�������V$N,�Q���F�ʯe�t����,�צp���t�g��$N���ݳ�\n"NOR
        +HIB"���G�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR
        ,victim);
        return;
        }
}


