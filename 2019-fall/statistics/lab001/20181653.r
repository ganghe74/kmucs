library(gdata)
data=read.xls("st_data.xls")
print(nrow(data))
print(ncol(data))
print(data[3,])
print(data[5,])
print(data[,1])
print(data[,3])