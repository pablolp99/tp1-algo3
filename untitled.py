fig_fb = sns.lineplot(results_bto.loc[results_bto.test_set==1].loc[results_bto.r==100].n.tolist(), results_bto.loc[results_bto.test_set==1].loc[results_bto.r==100].ms.tolist(), color='c')
fig_fb = sns.lineplot(results_bto.loc[results_bto.test_set==2].loc[results_bto.r==100].n.tolist(), results_bto.loc[results_bto.test_set==2].loc[results_bto.r==100].ms.tolist(), color='c')
fig_fb = sns.lineplot(results_bto.loc[results_bto.test_set==3].loc[results_bto.r==100].n.tolist(), results_bto.loc[results_bto.test_set==3].loc[results_bto.r==100].ms.tolist(), color='c')
fig_fb = sns.lineplot(results_btf.loc[results_btf.test_set==1].loc[results_btf.r==100].n.tolist(), results_btf.loc[results_btf.test_set==1].loc[results_btf.r==100].ms.tolist(), color='r')
fig_fb = sns.lineplot(results_btf.loc[results_btf.test_set==2].loc[results_btf.r==100].n.tolist(), results_btf.loc[results_btf.test_set==2].loc[results_btf.r==100].ms.tolist(), color='r')
fig_fb = sns.lineplot(results_btf.loc[results_btf.test_set==3].loc[results_btf.r==100].n.tolist(), results_btf.loc[results_btf.test_set==3].loc[results_btf.r==100].ms.tolist(), color='r')



fig_fb = sns.lineplot(results_fb.loc[results_fb.test_set==1].loc[results_fb.r==100].n.tolist(), results_fb.loc[results_fb.test_set==1].loc[results_fb.r==100].ms.tolist())
fig_fb = sns.lineplot(results_bto.loc[results_bto.test_set==1].loc[results_bto.r==100].n.tolist(), results_bto.loc[results_bto.test_set==1].loc[results_bto.r==100].ms.tolist())
fig_fb = sns.lineplot(results_btf.loc[results_btf.test_set==1].loc[results_btf.r==100].n.tolist(), results_btf.loc[results_btf.test_set==1].loc[results_btf.r==100].ms.tolist(), color='r')