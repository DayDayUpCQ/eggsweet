@set attachment=Release_Beta_V1.4.6.1011.zip
@set mailhead=E8000_Release_Beta_V1_4_6_1011

:del body.txt
:copy release_log.txt body.txt
blat distribution\body.txt -to zhuchao@zlg.cn    -subject %1 -attach %attachment%
blat distribution\body.txt -to yuyonghe@zlg.cn   -subject %1 -attach %attachment%
blat distribution\body.txt -to hekunzhi@zlg.cn   -subject %1 -attach %attachment%
blat distribution\body.txt -to lijun@zlg.cn 	 -subject %1 -attach %attachment%
del %attachment%
