#include <ansi.h>

// ���y
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i;
        int chance;

        obs = all_inventory(room);
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"�i�����j"+"�ǻD�����s���]��"HIW"����´�k�P"HIM"�۷|�A�}�d�����Aĭ�N�`���C\n"NOR,users());
                return;
        }
        
        if( random(100) < 40) {
                msg =  HBK "\n\t�����]�Ť@�����¡A���A���򳣬ݤ��M���C\n" NOR;
                msg += HIG "\n\t�A���T�Į��D�G�u�ӥi���F...�v\n" NOR;
                tell_object(room, msg);
                return;
        }

        msg = HIW "\n\t�b�Y������A�Ȫe�����P���䦳�������G���P�P�A�䤤�̫G���@���e�C�զ�A\n"
                   "\t�o�b�Ȫe��_��A�o�N�O´�k�P�C�t�@���G�P�b´�k�P���n���F�A�Y�Ȫe���F�n\n"
                   "\t��A�L�N�O�����P�C\n";

        // �j�_
       if( random(365) < chance ) {
                msg += HIM "\n\t�ֶ��˥��A���P�ǫ�A�Ⱥ~�|�|�t�סC�������S�@�۳{�A�K��ӫo�H���L�ơC\n"
                       "\t�X�������A�δ��p�ڡA���U�N���k���I�ⱡ�Y�O�[���ɡA�S�Z�b�´¼ǼǡC\n";
                 msg += HIG "\n\t�A�M���a�樣����´�k�P�N���۷|�A�ߤ��P�ʲ��W�A�Z����W�@�h�ӤF�C\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)  {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                obs[i]->add("popularity", 10 + random(3) );
                                obs[i]->add("war_art", 10 + random(3) );
                                obs[i]->add("exp", 50000 + random(40000) );
                }
        } else {
               msg += HIG "\n\t�A�������o����´�k���P�۷|�A�ߦ��ҷP���l�A�]�W���F�Z�����y�ڡC\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)  {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                obs[i]->add("popularity", 3 + random(3) );
                                obs[i]->add("war_art", 3 + random(3) );
                                obs[i]->add("exp", 20000 + random(25000) );
                }
        }

        tell_object(room, msg);
        message("world:world1:vision",HIM"�i�����j"+"�ǻD�����s���]��"HIW"����´�k�P"HIM"�۷|�A�}�d�����Aĭ�N�`���C\n"NOR,users());
}

// �ƥ�Ĳ�o
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/cominging/purple_sun/4fs")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}


