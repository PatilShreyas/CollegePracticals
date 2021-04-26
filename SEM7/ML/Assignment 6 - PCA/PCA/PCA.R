mydata<-read.csv("pca_dataset.csv")
attach(mydata)

names(mydata)
X <- cbind(calory,breakfast,lunch,dinner,exercise,body_shape)
# mean,median,25th and 75th quartiles, min, max
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

