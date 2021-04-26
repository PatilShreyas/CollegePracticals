mydata<-read.csv("pca_dataset.csv")
attach(mydata)

names(mydata)
X <- mydata[1:10,1:5]
summary(X)

cor(X)

pcal<-princomp(X, scores=TRUE, cor=TRUE)

summary(pcal)

loadings(pcal)

#Visualize the Principal Components
plot(pcal)
screeplot(pcal,type="line",main="Screen Plot")
biplot(pcal)
pcal$scores[1:10,]

