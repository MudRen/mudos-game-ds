/*****�C�i���N(Seven-love)    Update By Kkeenn****/
// �i�C�i���ˡj�G [exert seven-love love]  �W�[�����O
// �i�Ӯ��k���j�G [exert seven-love reap]  �l��ɤ��O
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void reap(object me, object *tar);
void love(object me, int ar1, int ar2);

int exert(object me,object target, string arg)
{
    int heal,reheal,sk,lv;
       sk = me->query_skill("seven-love");
    if( arg == "?" )
    {
    return notify_fail("�аѦ�help seven-love���A���o�i�@�B�ϥλ����C");
          }
          if( arg=="off" )
          {
              if( me->query_skill_mapped("force")!="seven-love" )
                  return notify_fail("�A�èS���b�B�\\�C\n");
              me->delete_temp("is_busy/seven-love");
              message_vision("$N���_���Ⲵ�C�C�C�}�A�����S�L�^���гB�C\n",me);
              me->map_skill("force");
              return 1;
          }

          if( me->query_skill_mapped("force")=="seven-love" )
                return notify_fail("�A�ٳB��C�i���˪��������C\n");

    if( !arg )
    return notify_fail("�аѦ�help seven-love���A���o�i�@�B�ϥλ����C");
                           if( me->query("hp") < 20 || me->query("ap") < 20 )
                               return notify_fail("�A�ثe�����p���ΡA�L�k�B�榹�\\�C\n");
                   if( arg=="reap" )    // �i�Ӯ��k���j
                       {
                           if( me->is_fighting() )
                           return notify_fail("�A�{�b�����ۥ��[, �S�Žm�\\�C\n");

                           sk = (int)me->query_skill("seven-love");
                           sk = (sk > 50) ? 50 + (( sk-50 )/2) : sk;
                           lv = (int)me->query("level");
                           heal = (int)me->query("max_ap");
                           reheal = (heal / 15) + ((sk/5)*3) + random(9) + (lv/2);
//                           if( me->query("quest/win") < 1 ) return notify_fail(HIW"�A�٨S�g�L�������j����I\n"NOR);
                           if( me->query("hp") < 30 )
                               return notify_fail("�A�ثe���x�����A, �L�k��_�ۨ����O�I\n");
                           if( me->query_skill("seven-love") < 60 )
                               return notify_fail("�A���C�i���N���Ť����I\n");
                           if( me->query_skill("force") < 70 )
                               return notify_fail("�A�����\\�ߪk���Ť����I\n");
                           if( me->query("level") < 30 )
                               return notify_fail("�A�����Ť����I\n");
                           if( me->query("ap") >= heal )
                               return notify_fail("�A�ثe�����\\���p�w�g�O���y�F�C\n");
                           me->receive_heal("ap",reheal);
                           me->receive_damage("hp", 17 + reheal/8 + random(4));
                           me->start_busy(2);
                           message_vision("$N�ߤ@��A�i�f�N�ަy�r�}�A�N�믫������t�@�عҬɡC\n",me);

                           me->improve_skill("seven-love",me->query("int")/4 + random(4));
                           me->improve_skill("force",me->query("int")/4 + random(3));

                           return 1;
                       }
                       if( arg == "love" ) //  �i�C�i���ˡj
                       {
                           int effect;
                           if( me->query("marry_id") )
                               return notify_fail("�A�w�b�e�N���A���Ӷ˱��H\n");
                           if( me->query("MKS") < 150 )
                               return notify_fail("�A����{���٤����H���@�����������O�I\n");
                           if( me->query_skill("force") < 50 )
                               return notify_fail("�A�����\\�ߪk�����j�I\n");
                           if( me->query_skill("seven-love") < 30 )
                               return notify_fail("�A���C�i���N�ٵL�۷����F�ѡM�ҥH�L�k�I��C�i���ˡI\n");
                           if( me->query("hp") < 100 )
                               return notify_fail("�A����O������I\n");
                           if( me->query("ap") < 100 )
                               return notify_fail("�A�����O���䨬�H�ϥX�C�i���ˡI\n");
                           if( me->query_temp("class_whip/in_love") )
                               return notify_fail("�A�w�g�ϥιL�C�i���ˤF�M�L�k�A�~��W�j�F�I\n");
      message_vision(HIG"$N"HIG"�����a�۹D�G�u�U�d�ߨ����H�A�ӤW�X��K�H�v�A�@�����C�i�����j���}�ӡC\n"NOR, me);
//                             message_vision(HIR"�u��$N"HIR"���������B�{�X�@���D����Ī�����A$N"HIR"�����O�j�j���@�F�I�I\n"NOR, me);

                           effect = sk*3/4;

                           me->add_temp("apply/damage", effect);
                           me->receive_damage("ap", 100);
                           me->receive_damage("hp", 50);
                             if( me->is_busy() || me->is_fighting() )
                               me->add_busy(2);
                           else me->start_busy(1);

                           me->set_temp("class_whip/in_love", 1);
                           me->improve_skill("seven-love",me->query_int()/4 + random(3) );
                           me->improve_skill("force",me->query_int()/4 + random(3) );
                   me->skill_active("seven-love",(: call_other,__FILE__,"seven_love",me, effect:), 60);
                           return 1;
                       }
                       else return notify_fail("�C�i���N�S���o�إ\\��I\n");

}

void seven_love(object me, int effect)
{
    if(!objectp(me)) return;
    me->add_temp("apply/damage", -effect);
    me->delete_temp("class_whip/in_love");
      message_vision("$N�q�C�i���˪��C�I��������_�L�ӤF�C\n", me);
    return;
}

void delay(object me)
{
    int sk_level, lv,i;
    sk_level = me->query_skill("seven-love");
    lv = me->query("level");
    i = me->query_int();

    if( !me ) return;

    if( me->query_skill_mapped("force")!="seven-love" ) return;

    if( me->query("ap") < 13 || me->query("hp") < 13 )
    {
        message_vision("$N�߯��p�p�F���A£�M����F�B�\\�C\n",me);
        me->delete_temp("is_busy/seven-love");
        me->map_skill("force");
        return;
    }
    else if ( sk_level < 50 )
    {
        me->receive_damage("ap",20);
        me->receive_damage("hp",10);
    }
    else if ( sk_level > 49 )
    {
        me->receive_damage("ap",22);
        me->receive_damage("hp",12);
    }
    me->improve_skill("force",1 + random(5+lv/2) + (sk_level/5) + (i/3) );
    me->improve_skill("seven-love",1 + random(5+lv/2) + (sk_level*3/8) + (i/3) );
me->skill_active( "seven-love",(: call_other, __FILE__, "delay", me :), 3);
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}

void skill_improved(object me) // �`�N, �@��skill��W�[���ݩ��`�M�H 5 ���W��
{
    int b,c;
    b = me->query_skill("seven-love",1);
    c = me->query("skill/seven-love");

    if( b % 20==19 && b > c)
    {
        if(random(2))
        {
            tell_object(me, HIR "�A���ʧ@�ѩ��鮩�C�i���N�����ӧ�[���դF�C\n" NOR);
            me->add("addition/dex", 1);
        }
        else
        {
            tell_object(me, HIR "�A�����ѩ�⮩�C�i���N�����ӼW�j�F�C\n" NOR);
            me->add("addition/con", 1);
        }
        me->set("skill/seven-love", b);
    }
    me->save();
}

int improve_limite(object ob)
{
    int a;
    a=(ob->query("level")*3)+(ob->query_int());
    if( a > 90 && ob->query("level") < 26 ) a=100;
    else if( a > 100 ) a =100;
    return a;
}
