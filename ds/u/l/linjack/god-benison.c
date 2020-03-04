#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
        int sk,i,inn;
        object ob,*ob2;

        sk=me->query_spell("god-benison");
        inn=me->query_int();

        if(sk < 20) tell_object(me,"�A���u����ë�g�v�٥������J�A�|�L��O�ϥΡC\n");
        if(me->is_busy() ) return notify_fail("�A�{�b�����ۡA�S���ŧa�C\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("�A�ثe�����骬�A�L�k�ϥΡu����ë�g�v���C\n");

        if(me->is_fighting() )
        {
        if(!target) return notify_fail("�A�n��֬I�i�u����ë�g�v�H�H\n");

        switch( random(3) ) 
        {
        case 0:
                message_vision(HIG
                "$N�q��u����ë�g�v���u���X�v�Z�G\n\n" NOR
        +HIM    "      �u�s�������X�A��뽪���СC�v\n" NOR
        +HIM    "      �u���ϯB�_���A����Ӫ��ɡC�v\n" NOR
        +HIY    "\n$N�Y���W��Ƥة����E�ƹD�L�Ϊ����b��....\n" NOR
                ,me);
        ob2 = all_inventory(environment(me));

        for(i=0; i<sizeof(ob2); i++)
        {
                if( !living(ob2[i]) || ob2[i]==me || !ob2->is_fight(me)|| !ob2->is_kill(me) ) continue;

                message_vision(HIY"$N�q��@�n�G�u�h�v�A�@�ƪ����b�𨳱��L���L��a��$n�g�h�I�I\n" NOR,me,ob2[i]);
                if(random
(ob2[i]->query_skill("dodge")/2+ob2[i]->query_shield() )< random(sk+inn) )
                {
                        message_vision(HIR"\n$N�{�����Τ��F�D�����b��A�uť$N�G�I�@�n�A�ݨӨ��ˤ����C\n\n"NOR,ob2[i]);                 
                        ob2[i]->receive_damage("hp",sk/2+random(inn)*2 );
                }
                else
                        message_vision(HIG"\n�uť$N��I�@�n�A�ϺɦY�����O��A�n���e�����}�F�����b�𪺰l���C\n\n"NOR,ob2[i]);
        }
        break;
        
        case 1:
                message_vision(HIG
                "$N�q��u����ë�g�v���u�����v�Z�G\n\n" NOR
        +HIM    "      �u��b�B�I���W�C�A���Y�����b���D�C�v\n" NOR
        +HIM    "      �u�ѭ��f�ư_��ȡA�Z�e���Ұʷ��Y�C�v\n" NOR
        +HIC    "\n�u��$N�Y�W�@�D�벴�j���A���M�X�{�T�쯫�N�A�­������A���i�@�@�I�I\n" NOR
,me);

        message_vision(HIY "\n$N���⵲�W�A�C�����n�A�X�ϡu��b�v�A�u���Y�v�A�u�ѭ��v�޼S�P��$n�I�I\n"NOR,me,target);

        if(random(target->query_skill("dodge")/2+target->query_shield() )< random(sk+inn) )
        {
                message_vision(
                MAG"��b���⤤���b�����A�Q�T�M�A��V$N�Y�B��B�ݤT�L�n�`�I�I\n" NOR
        +       MAG"���Y�����R��W�G��ܻ�P�A�C�C�|�Q�E���s��$N�ݡB�y�U�n�`�۩I�I�I\n" NOR
        +       MAG"�ѭ�����B��W�ﰩ�j�A�@���u�ۯ}����v�A�Q���O�D��V$N�ݤf�n�ޡI�I\n" NOR
        +       HIR"\n$N�G�I�@�n�A�n�ɦ��|�q�B�g�R�Ƥf�A��A�ݨӨ��ˤ����C\n\n" NOR
        ,target);
        target->receive_damage("hp",sk+inn*3);
        }
        else
        {
                message_vision(HIG"\n$n�ϥX�����ѼơA�T�V���k�}�F�o�@���C\n\n"NOR,me,target);
        }
        break;

        case 2:
                 message_vision(HIG
                 "$N�q��u����ë�g�v�����u���͡v�Z�G\n\n" NOR
        +HIM     "      �u�j�v�����A�U�����l�C�v\n" NOR
        +HIM     "      �u�ܫv�[���A�U�����͡C�v\n" NOR    
        +HIC     "\n$N���⥪�k�e��A�x�X�H�Ŧ⤧���A�K���ť��|���A�ιγ�¶��$n�C\n"NOR,me,target);

        if(random(target->query("inn")/2+target->query_shield() )< random(sk+inn) )
        {
                 message_vision(HIC
                    "�H�Ŧ⤧���ĦV$n�餺�A�u��$n���n�b�a�W�A�C�C�a�q$n����̴��X\n" NOR
        +HIR        "����⪺�����A$N���X����A���ئR�o�A�������w�w���Q$N�l���F�C\n\n" NOR,me,target);

        target->receive_damage("mp",sk+inn);
        me->set("heal_mp",(sk+inn)/2);
        }
        else
        {
                message_vision(HIG"\n$n�W�W�i�i�A����k�ҡA�k�X�F�ť�����¶�C\n\n"NOR,me,target);
        }
        break;
        }
        
        me->start_busy(2);
        me->receive_damage("mp",((sk/2)+random(inn/2)) );
        me->improve_spell("god-benison",inn/10+random(3));
        }
        else
        {

        if(sk>40 && random(3)==1 )
        {
                message_vision(HIG
                "$N�q��u����ë�g�v���u�j�D�v�Z�G\n\n" NOR
        +HIM    "      �u�Ѫ���g�m���}�A�j���x�����E���C�v\n" NOR
        +HIM    "      �u�U���@�ɪg�t�ơA�a�͹��R�K����C�v\n" NOR
        +HIW    "\n�n��$N�����W�U��¶�ۤ@�}�ե��A�M�ấ�����h�C\n" NOR
                ,me);

                        if(me->query("wound/head") )
                           me->receive_curing("head",sk/20+inn/8);
                        if(me->query("wound/hand") )
                           me->receive_curing("hand",sk/20+inn/8);
                        if(me->query("wound/foot") )
                           me->receive_curing("foot",sk/20+inn/8);
                        if(me->query("wound/body") )
                           me->receive_curing("body",sk/20+inn/8);
        }
        else
        {
                message_vision(HIG
                "$N�q��u����ë�g�v���u�C��v�Z�G\n\n" NOR
        +HIM    "      �u�����b�W�A���^�B��C���f�f�A�N�y�y�C�v\n" NOR
        +HIM    "      �u�Y�o���H�ޡA�ܤƳ��s�X�j�W�C�v\n" NOR
        +HIB    "\n\n�n��$N���|�P���v�����A�����}�}....\n" NOR
                ,me);


                if(me->query_temp("call_ghost")<=3 && (sk+me->query_int() ) >random(40) )
                {
                ob=new(__DIR__"npc/ghost");
                ob->set("level",random((sk+me->query_int())/3) );
                ob->set_temp("host",me->query("id") );
                message_vision(HIW "\n�u��$N���Ǫ������@�_�A�����۰��S��ڡA�������E���@�ѤH��.....\n"NOR,me);
                me->add_temp("call_ghost",1);
                ob->move(environment(me) );
                }
                message_vision(HIW "\n�u��$N�|�P���v���q�A�S��_�F���`���ˤl�A�ݨӤ���Ƥ]�S���o�͡C\n"NOR,me);
        }
        me->start_busy(2);
        me->receive_damage("mp",((sk/2)+random(inn)/2) );
        me->improve_spell("god-benison",inn/10+random(3));
        }
        return 1;
}
