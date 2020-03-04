#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target, string arg)
{
        int sk,i,inn,cost,he,si;
        object *enemy;
        sk=me->query_spell("moxibustion");
        inn=me->query_int();

        if( environment(me)->query("no_cast") )
                return notify_fail("�o�̤���w�b�C\n");

        if( environment(me)->query("no_magic") )  // (COM) cast.c �̭��O�� no_magic, �̦n�]�[�W�h
                return notify_fail("�o�̤���w�b�C\n");

        if( sizeof(me->query_temp("is_busy")) )
                 return notify_fail("�A�{�b���b���A�L�k�ϥΪ��ްw�b�@�C\n");

        if( !present("needle",me) )
                return notify_fail("�A�������w�~��ϥΰw�b�@�C\n");

        if( me->query("mp") < 20)
                return notify_fail("�A�ثe�����骬�A�L�k�ϥΡu���ްw�b�v���C\n");

        if( me->is_fighting() )
                return notify_fail("�԰����A�L�v�ϥΡu���ްw�b�v.");

        if( !me->query("env/moxibustion") || me->query("env/moxibustion") == 0 || me->query("env/moxibustion") > 4)
                return notify_fail("�Х� set moxibustion 1 �ϥΪ��ްw�b�Ĥ@���\�O�A�|���ðݥi help moxibustion�C\n");

        if( !me->visible(target) ) // (COM) �ˬd�ݤ��ݪ���H
                return notify_fail("�o�̨S���o�ӤH�I\n");

        if( (int)me->query("env/moxibustion") == 1) // ����Z
        {
	if(me->query("hp") >= me->query("max_hp"))
                        return notify_fail(CYN"�A�{�b�èS�����ˡC\n"NOR);

        if(me->query("mp") < cost )
                        return notify_fail(CYN"�A���]�O�����C\n"NOR);

                he=(inn)+(sk)*2;
                cost=(he)-(inn)-(sk);
                si=random(inn/2);
                message_vision(YEL"\n$N���ؾ���, �N��l�B��⤤�Ȱw, �ǳƨϥX�|���w�b���u"+HIC+"�i����j"+NOR+"�v"+YEL+"�Z�C"+NOR+"\n"NOR, me);
                message_vision(YEL"\n$N���M�M�S�@�n, �⤤�Ȱw���I�߯�, �ʦ��F�ˤf���˶� !!\n"NOR, me); // (COM)�[�F$n�]���n��_�O�H
                message_vision(YEL"\n$N���ˤf����y��������F....\n"NOR,me ); // (COM) msg �ǩǪ��� !!
                me->start_busy(2);  //�I�k�ʧ@�ɶ�
                me->receive_damage("mp",cost); //�I�k��MP
                me->receive_heal("hp",he); // �^�_HP // (COM) �� receive_heal ��!!, ��H�令 target
                me->improve_spell("moxibustion",si);
                return 1;
        }
        
        if( (int)me->query("env/moxibustion") == 2) // ����Z
        {

	if(sk < 25) 
                return notify_fail(CYN"�A���u���ްw�b�v�٥������J�A����ϥΥ|���w�b���u"+HIC+"�i����j"+NOR+"�v"+YEL+"�Z�C"+NOR+"�C\n"NOR);

	if(me->query("ap") >= me->query("max_ap"))
                        return notify_fail(CYN"�A�����O�w�b�q�p���A�C\n"NOR);

        if(me->query("mp") < cost )
                        return notify_fail(CYN"�A���]�O�����C\n"NOR);

                he=(inn)+(sk);
                cost=(he)-(inn)/2-(sk)/2;
                si=random(inn/2);
                message_vision(YEL"\n$N����B�l, �l�z����, �ǳƨϥX�|���w�b���u"+HIC+"�i����j"+NOR+"�v"+YEL+"�Z�C"+NOR+"�C\n"NOR,me);
                message_vision(YEL"\n$N���M�N�⤤�Ȱw�ϱo�ַ�, �I�M���нѥ� !!\n"NOR,me);
                message_vision(YEL"\n$N�P��@�ѷx��ۤ��Ъ@�W....\n"NOR,me);
                me->start_busy(2); //�I�k�ʧ@�ɶ�
                me->receive_damage("mp",cost); //�I�k��MP
                me->receive_heal("ap",he); // �^�_HP // (COM)
                me->improve_spell("moxibustion",si);
        }

        if( (int)me->query("env/moxibustion") == 3) // �}�ѳZ
        {
	if(sk < 60) 
                return notify_fail(CYN"�A���u���ްw�b�v�٥������J�A����ϥΥ|���w�b���u"+HIC+"�i�}�ѡj"+NOR+"�v"+YEL+"�Z�C"+NOR+"�C\n"NOR);
	if(me->query("hp") >= me->query("max_hp"))
                        return notify_fail(CYN"�A�{�b�èS�����ˡC\n"NOR);

	if(me->query("ap") >= me->query("max_ap"))
                        return notify_fail(CYN"�A�����O�w�b�q�p���A�C\n"NOR);

        if(me->query("mp") < cost )
                        return notify_fail(CYN"�A���]�O�����C\n"NOR);
                he=(inn)+(sk)*2;
                cost=(he)-(inn)*1.5;
                si=random(inn/3);
                message_vision(YEL"\n$N�B�_�����F�O, �u��$N�Y���}�}�շϫ_�X, �ǳƨϥX�|���w�b��\��\�\\�O\�u"+HIC+"�i�}�ѡj"+NOR+"�v"+YEL+"�Z�C"+NOR+"�C\n"NOR,me);
                message_vision(YEL"\n$N���M�N�⤤�Ȱw�ϱo���p���s, �b�ɱN�����G�ߥ��q !!\n"NOR,me);
                message_vision(YEL"\n$N�uı�n���@�Ѻu���y�L����, �κZ�L��! \n"NOR, target);
                me->start_busy(3); //�I�k�ʧ@�ɶ�
                me->receive_damage("mp",cost); //�I�k��MP
                me->receive_heal("ap",he); // �^�_AP // (COM)
                me->receive_heal("hp",he); // �^�_HP // (COM)
                me->improve_spell("moxibustion",si);
        }
        
        if( (int)me->query("env/moxibustion") == 4) // ���@�Z
        {
		if(sk < 20) 
                return notify_fail(CYN"�A���u���ްw�b�v�٥������J�A����ϥΥ|���w�b���u"+HIC+"�i���@�j"+NOR+"�v"+YEL+"�Z�C"+NOR+"�C\n"NOR);

		if(me->query("mp") < cost )
                        return notify_fail(CYN"�A���]�O�����C\n"NOR);

		if(target->query("hp") >= target->query("max_hp"))
                        return notify_fail(CYN"�L�{�b�èS�����ˡC\n"NOR);
                if(!userp(target))
                        return notify_fail("�A�u��缾�a�ϥ����˥\\��@�C\n");
                if( target==me )
                        return notify_fail(CYN"�u"+HIC+"�i���@�j"+NOR+"�v"+CYN+"�Z�u���H�ϥ�."+NOR+"\n");
                he=(inn)+(sk)*1.5;
                cost=(he)-(inn)-(sk);
                si=random(inn/3)+(inn/3);
                message_vision(YEL"\n$N�B�_�F�O, �����x, �ǳƨϥX�|���w�b���u"+HIC+"�i���@�j"+NOR+"�v"+YEL+"�Z�C"+NOR+"�C\n"NOR,me);
                message_vision(YEL"\n$N�N�Ȱw�ֳt�I�L"+target->query("name")+"�߯�,",me);
                message_vision(YEL" �ʦ�"+target->query("name")+"���˶�!\n"NOR,me);
                message_vision(YEL"\n$N�P��@�Ѽ��������ˤf, �y�ɵκZ�\\�h! \n"NOR,target);
                me->start_busy(3); //�I�k�ʧ@�ɶ�
                me->receive_damage("mp",cost); //�I�k��MP
                target->receive_heal("hp",he); // �^�_AP // (COM)
                me->improve_spell("moxibustion",si);
        }
        else return 0;
        return 1;
}
