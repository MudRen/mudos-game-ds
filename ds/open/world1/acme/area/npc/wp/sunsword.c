/**  ��s���F���Z�ФG��̤l�H�~, ��L **
 **  �����̤l�ϥη|�X�{��Bug    **
 **  By Kkeenn@DS 2002/7/19       **/
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIW "���C" NOR, ({ "se ri sword","sword" }) );
        set_weight(17000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("material","crimsonsteel");
        set("limit_str",20);
                set("limit_int",25);
                set("long",
                        "�o�O�@��{�ۤ�Ӷ��٭n�G�����~�����C�A\n"
                        "�C�e������A���o���O�����A�����O�Ѧ��\n"
                        "�����ű�y�Ӧ��A�b�������U�{�{�ۡA�D�`\n"
                        "ģ���C\n");
                set("wield_msg", "$N�q�I��C�T����X�@������{�{��$n�A���b�⤤��Z���C\n");
                set("unwield_msg", "$N�N�⤤��$n���J�I��C�T���C\n");
                set("value",8000);
                  set("replica_ob",__DIR__"sunsword2");
                set("volume",5);
        }
                  set("weapon_prop/dex", 1);
                  set("weapon_prop/int",3);

                set("weapon_prop/hit", 10);
                 set("weapon_prop/wit", 1);
                 set("weapon_prop/bar", -1);
                set("weapon_prop/god-fire",10);
                  set("weapon_prop/shield",10);
        init_sword(67,TWO_HANDED);
        setup();
}

void attack(object me,object target)
{
          int SK;
          int INN;
        ::attack();
           if( !me
           || me->query("class1")!="���Z��" 
           || me->query("class2")!="���Z��" 
           || me->query("level") < 30
           || me->is_busy()
           || me->query_spell("god-fire") < 80
           || me->query("hp") < 300 
           || me->query("mp") < 300 
           || random(100) <70 )
                return;        
        ::attack();
        SK=me->query_spell("god-fire");
        INN=me->query_int();
        message_vision(
        HIG "$N�C�Y�ֳt�a��F�M�u����ë-�����g�v�A�K�ɥ|�g���_�F�@�D����I�I\n" NOR
        + HIR "\n�|�P�����K���t�Ӿ��ʦa�E���F�@�Ӧ�������������A�L�C�b$N�Y�W\n" NOR,
        me);
        SPELL_D("god-fire")->cast_fire(target,me,SK,INN);
        message_vision(
        HIG "$N�����@�}�F�O�A���W�������]�����F�C\n" NOR,me);
        me->receive_damage("mp",40);
}
