#include <ansi.h>

// ���y
private void do_bonus(object room)
{
        object *obs;
        string msg;
         int i, chance;

        obs = all_inventory(room);
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"�i�����j"+"�s���̹D"HIY"���벮��"HIM"�A�����D�Z�A�L�ƹC�H�g�Ĥ��w�C\n"NOR,users());
                return;
        }
        
          if( random(100) < 20) {
                msg =  HBK "\n\t�u���Ƕ��h�h�A������L�k�S�y�C\n" NOR;
                msg += HIG "\n\t�A���T�Į��D�G�u�ӥi���F...�v\n" NOR;
                tell_object(room, msg);
                return;
        }
        chance = sizeof(obs);
        if(chance > 20) chance = 20;

        msg = HIW "\n\t�֤W��ӡA�Ȥѩ�B�B���B��C������B���־�áA�@�n�j���C\n"
                   "\t�ְ��B���B�@�ɡA�̼��ɩ�׮ɸ`�C�ݹ߮Z�B�t�N���T�L�A���ؾv�C\n"
                   "\t�Y�o����p���]�A�H�������ݩӧO�C��q�e�B�����`���w�A�k�ɻ��C\n";

        if( chance < random(365)) {
               msg += HIM "\n\n\t���를�X�s�s���A����d�V�ͥղ@�C\n" NOR;
               msg += HIM "\t�@�M���ɻ����F�A�ö����a�p�Y�ܡC\n" NOR;
               msg += HIG "\n\t�������o�X�����A�A���F�W����ê���������A�b�Z���W���׬��S��W�@�h�ӤF�C\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(5) );
                                        obs[i]->add("war_art", 10 + random(5) );
                                        obs[i]->add("exp", 25000 + random(20000) );
                }

        } else {
                 msg += HIG "\n\t�A��۲��䪺����A�ߤ��Y���Ү��A�b�Z���W���׬��y���i�i�F�C\n\n" NOR;
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 3 + random(2) );
                                        obs[i]->add("war_art", 3 + random(2) );
                                        obs[i]->add("exp", 20000 + random(5000) );
                }

        }

        tell_object(room, msg);
        message("world:world1:vision",HIM"�i�����j"+"�s���̹D"HIY"���벮��"HIM"�A�����D�Z�A�L�ƹC�H�g�Ĥ��w�C\n"NOR,users());
}

// �ƥ�Ĳ�o
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/faceoff/sky/moon")))
                do_bonus(room);
                
}

void create() 
{ 
        seteuid(getuid()); 
}

