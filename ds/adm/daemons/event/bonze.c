// tmr 2006/11/14

#include <ansi.h>

// ���y
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i, chance;

        obs = all_inventory(room);
        if (sizeof(obs) < 1) {
            message("world:world1:vision",HIM"�i�����j"+"ť��"HIY"�ⶳ�p�����"HIM"�X�{�A�O�H�Ĭ��[��A�g�Ĥ��w�C\n"NOR ,users());
        	return;
        }
        
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
        
        r = random(365);
          if (r < chance )
        {
                //msg = HIY "�i�۵M�_�[�j�ⶳ�p����X\n"NOR;
                msg = HIR "\n\t�u���Ӷ��@�I�@�I���ɤF�_�ӡA�������e�@�G�A�@�D���w�X�{�b���ڡA\n"
                          "\t�a�a������G���@�Ӧ�v�ߦb���A�O�H�ĸr���w�C\n" NOR;
                msg += HIG "\t�A�߭ߤ��ϩ��o��F�򯪪����ܡA�n�ɦ��T��y�}���Pı�C\n\n" NOR;

                // �W�[�n���԰����N
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 20 + random(10) );
                                        obs[i]->add("war_art", 20 + random(10) );
                                        obs[i]->add("exp", 30000 + random(10000) );
                    }
                    
                tell_object(room, msg);
                message("world:world1:vision",HIM"�i�����j"+"ť��"HIY"�ⶳ�p�����"HIM"�X�{�A�O�H�Ĭ��[��A�g�Ĥ��w�C\n"NOR ,users());
        } else
        if (r < 250)
        {
                //msg = HIY "�i�۵M�_�[�j�ⶳ�p����X\n"NOR;
                msg = HIG "\n\t�A�b�ⶳ�p�s�W�Y���X�O�H���m���ɡA��~�Ⲥ�ⶳ�p���m�q�I�_�C\n"NOR;
                
                switch (random(3))
                {
                case 0:
                        msg += HIW "\t�@��"HIR"����"HIW"�D�X�ѻڡA�M�g�o�h�r�|�A���~���c�A������A�ɩܬ����C\n" NOR;
                        break;
                case 1:
                        msg += HIW "\t���M���@��"HIR"����"HIW"�D�F�W�ӡA�Ѧa�����n�ɽ��׵L��A�u�g�o�A�������L�k�C�}�C\n" NOR;
                        break;
                default:
                        msg += HIW "\t�Z�M���e�����|�g�A�@��"HIR"����"HIW"�T�T�ɰ_�C\n" NOR;
                        break;
                }
                msg += HIG "\t�A���Y�{�L�@�D�F���A���G����F�Y�رҭ}�C\n\n" NOR;
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) );
                                        obs[i]->add("popularity", 3 + random(3) );
                                        obs[i]->add("war_art", 3 + random(3) );
                                        obs[i]->add("exp", 5000 + random(5000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"�i�����j"+"ť��"HIY"�ⶳ�p�����"HIM"�X�{�A�O�H�Ĭ��[��A�g�Ĥ��w�C\n"NOR ,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t�����Ӷ��a�a���諸�N�n�ɤW�ӡA�o���@���Q���ƹL�A�B�F�ӲϲϹ��C\n" NOR;
                        break;
                case 1:
                        msg = WHT "\n\t�A���e�V�ӶV�G�A���O����n���A���A���򳣬ݤ��M���C\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t���亥�����o�աA���O�@�h�@�h������N���Y���o���~�@�����ݤ����C\n" NOR;
                        break;
                }
                msg += HIG "\t�A�ߤ��s�ġG�u�ӥi���F�I�v\n\n" NOR;
                tell_object(room, msg);
        }
}

//�ƥ�Ĳ�o
void trigger_event()
{
        object room;

        // �ⶳ�p����X
        if (objectp(room = find_object("/open/world1/tmr/advbonze/summit1")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
//      message("channel:sys", HIR"�i�۵M�_�[�j�ⶳ�p����X�C\n"NOR, users());
//      trigger_event();
}
